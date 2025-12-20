# Conan Starter Project

`conan-starter` is a starter project to easily get started to using conan. This is a template repository \
that you can use.

## Conan Setup

To get all of Engine3D packages, just run this conan command. To start using them.

```
conan remote add engine3d-conan https://libhal.jfrog.io/artifactory/api/conan/engine3d-conan
```

## Build Starter

Run this conan command to build the project with `-b missing` on the first build, so conan can install any missing dependencies.

```
conan build . -b missing
```

## Running the Starter

Running the executable, `./build/Release/Starter`


# Notes

In case, you need to make sure the clangd is not throwing any errors when using C++ modules. Make sure to apply the `--experimental-modules-support` flags in the clangd arguments tab.

