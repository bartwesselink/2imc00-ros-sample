from setuptools import setup

package_name = 'environment_scanner'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='b.wesselink',
    maintainer_email='b.b.a.wesselink@student.tue.nl',
    description='Scans and publishes an environment map.',
    license='LGPL-3.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'interface = environment_scanner.scanner_member_function:main',
        ],
    },
)
