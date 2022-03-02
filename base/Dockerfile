FROM ros:foxy
ARG NODE_NAME
ARG BUILD_INTERFACES=false
ENV NODE_NAME ${NODE_NAME}

# define global environment
# ${NAME}

# create separate workspace
RUN mkdir -p /app \
  && apt-get update \
  && apt-get install -y python3-pip \
  && apt-get clean autoclean \
  && apt-get autoremove --yes \
  && rm -rf /var/lib/{apt,dpkg,cache,log}/

WORKDIR /app

# copy required files
COPY ./$NODE_NAME/ /app/$NODE_NAME/

# copy interfaces, note that they might not be built depending on the argument
COPY ./communication_interfaces/ /app/communication_interfaces/

# build package(s)
RUN rosdep install -i --from-path /app --rosdistro foxy -y \
 && (pip3 install -r /app/$NODE_NAME/requirements.txt || true)

RUN $BUILD_INTERFACES \
 && . /opt/ros/foxy/setup.sh \
 && colcon build --packages-select communication_interfaces --merge-install \
 || true

RUN . /opt/ros/foxy/setup.sh \
  && colcon build --packages-select $NODE_NAME --merge-install

# source entrypoint
RUN sed --in-place --expression \
     '$isource "/app/install/setup.bash"' \
     /ros_entrypoint.sh

# launch ros package
CMD ros2 run ${NODE_NAME} interface
