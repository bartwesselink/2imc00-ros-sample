from setuptools import setup

package_name = 'robot_platform'

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
    description='Can move and publishes correct location.',
    license='LGPL-3.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'interface = robot_platform.platform_member_function:main',
        ],
    },
)
