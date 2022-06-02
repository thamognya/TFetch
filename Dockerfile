ARG BASE_IMAGE=ubuntu:latest
FROM $BASE_IMAGE

RUN mkdir /TFetch
ADD ./** /TFetch/.
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    git \
    curl \
    neovim \
    build-essential \

#CMD tail -f /dev/null
#CMD /bin/bash
