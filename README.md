# OpenGL - Notes

## Issues

### Run with docker

#### 1. qemu related error

```
qemu: uncaught target signal 11 (Segmentation fault) - core dumped
```

##### **Solution**: upgrading Docker Desktop to 4.11.1 (M1 chip).

> Reference: [stackoverflow / qemu: uncaught target signal 11 (Segmentation fault) - core dumped in docker containers](https://stackoverflow.com/questions/68862313/qemu-uncaught-target-signal-11-segmentation-fault-core-dumped-in-docker-con)
