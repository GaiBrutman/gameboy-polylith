# gameboy-polylith

## Introduction

This is an example of a polylith project for a gameboy CLI application.

For more information about polylith, see [Polylith](https://polylith.gitbook.io/polylith).

The project is divided into three parts:

### Components

Bricks of logic that can be used in multiple places. They are the building blocks of the project.

### Bases

A base is a collection of components that are used together. Bases are the foundation of the project.

### Projects

A project is a recipe that defines how to build an application.

It contains a base and components that are used to build the application.
Platform specific code / configuration can be added to the project.

The root `Sconstruct` file lives in the project folder and responsible of setting the build environment and producing the final product.

## Installation

To build the project, install the python requirements:

```py
pip install -r requirements.txt
```

## Build

To build the gameboy project, run the following command:

```sh
scons -C projects/gameboy
```

Then run the final product:

```sh
./bases/gameboy/gameboy
```
