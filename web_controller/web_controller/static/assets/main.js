const element = document.querySelector('.map');
const distanceValue = document.querySelector('.distance-value');

const updateData = async () => {
    const { environment, robot, distance } = await fetch('/api/map')
        .then(response => response.json())
        .catch(() => setTimeout(updateData, 1000));

    const size = Math.sqrt(environment.length);
    element.style.setProperty('--size', size);

    element.innerHTML = environment
        .map((it, index) => {
            const y = 20 - (Math.floor(index / size));
            const x = (index % size) + 1;

            const isRobot = robot.x === x && robot.y === y;

            return `<div class="tile ${it === 1 ? 'crate' : ''} ${isRobot ? `robot robot-${robot.rotation}` : ''}"></div>`
        })
        .join('');

    distanceValue.innerText = distance;

    setTimeout(updateData, 200);
};

updateData();