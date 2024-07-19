# OpenGL - Notes

## Issues

### Run with docker

#### 1. qemu: uncaught target signal 11

錯誤如下:

```
qemu: uncaught target signal 11 (Segmentation fault) - core dumped
```

Solution:

- `upgrading to Sonoma 14.5 and Docker Desktop to 4.32.0`

Reference:

1. [stackoverflow / qemu: uncaught target signal 11 (Segmentation fault) - core dumped in docker containers](https://stackoverflow.com/questions/68862313/qemu-uncaught-target-signal-11-segmentation-fault-core-dumped-in-docker-con)

2. [ Mac M1 - after upgrade to Docker Desktop 4.27.1 docker container with java fails with qemu: uncaught target signal 11 (Segmentation fault) - core dumped #7172 ](https://github.com/docker/for-mac/issues/7172)
