from setuptools import setup

package_name = 'cmd_wheel'

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
    maintainer_email='b.wesselink@recognize.nl',
    description='Command line wheel.',
    license='LGPL-3.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'interface = cmd_wheel.wheel_member_function:main',
        ],
    },
)
