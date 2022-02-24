const element = document.querySelector('.map');
const robotElement = document.querySelector('.robot');
const wrapperElement = document.querySelector('.robot');
const distanceValue = document.querySelector('.distance-value');

const updateData = async () => {
    const { environment, robot, distance } = await fetch('/api/map')
        .then(response => response.json())
        .catch(() => setTimeout(updateData, 1000));

    const size = Math.sqrt(environment.length);
    wrapperElement.style.setProperty('--size', size);

    element.innerHTML = environment
        .map((it, index) => {
            const y = 20 - (Math.floor(index / size));
            const x = (index % size) + 1;

            return `<div class="tile ${it === 1 ? 'crate' : ''}"></div>`
        })
        .join('');

    robotElement.style.setProperty('--rotate', robot.rotation);
    robotElement.style.setProperty('--x', robot.x);
    robotElement.style.setProperty('--y', robot.y);

    distanceValue.innerText = distance;

    setTimeout(updateData, 500);
};

updateData();