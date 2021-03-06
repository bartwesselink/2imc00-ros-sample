from setuptools import setup
from glob import glob
import os

package_name = 'web_controller'

assets_files = glob(package_name + '/static/assets/**/*', recursive=True)
assets_files = [f for f in assets_files if os.path.isfile(f)]

static_files = glob(package_name + '/static/*', recursive=True)
static_files = [f for f in static_files if os.path.isfile(f)]

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('static/', static_files),
        ('static/assets/', assets_files)
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='b.wesselink',
    maintainer_email='b.b.a.wesselink@student.tue.nl',
    description='Web interface for command line wheel.',
    license='LGPL-3.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'interface = web_controller.controller_member_function:main',
        ],
    },
)
