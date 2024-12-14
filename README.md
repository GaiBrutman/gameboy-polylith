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

## Build Sytem

### `projects/gameboy/Sconstruct`

This is the main SCons build script for the `gameboy` project. It sets up the build environment and includes other SConscript files to build the project.

1. **Create Environment**:

    ```py
    env = Environment()
    ```

    This line creates a new SCons build environment.

2. **Include Component SConscript Files**:

    ```py
    SConscript('../../components/game/Sconscript', exports='env')
    SConscript('../../components/simple_game/Sconscript', exports='env')
    SConscript('../../components/ui/Sconscript', exports='env')
    ```

    These lines include the SConscript files for various components. The `exports='env'` argument passes the build environment to these scripts.

3. **Include Project-Specific Component SConscript File**:

    ```py
    SConscript('../../components/curses_ui/Sconscript', exports='env')
    ```

    This line includes the SConscript file for the `curses_ui` component.

4. **Include Base SConscript File**:

    ```py
    program = SConscript('../../bases/gameboy/Sconscript', exports='env')
    ```

    This line includes the SConscript file for the `gameboy` base and assigns the result to the `program` variable.

5. **Set Default Target**:

    ```py
    # copy the target program to the build directory
    env.Command("build/gameboy", program, Copy("$TARGET", "$SOURCE"))
    ```

    This line copies the target program to the `build` directory.

### `bases/gameboy/Sconscript`

This SConscript file defines how to build the `gameboy` base.

1. **Import Environment**:

    ```py
    Import("env")
    ```

    This line imports the build environment passed from the main `Sconstruct` file.

2. **Include Component SConscript Files**:

    ```py
    SConscript('../../components/game/Sconscript', exports='env')
    SConscript('../../components/simple_game/Sconscript', exports='env')
    SConscript('../../components/ui/Sconscript', exports='env')
    ```

    These lines include the SConscript files for various components.

3. **Build Program**:

    ```py
    program = env.Program(target="target.bin", source=['src/main.c'])
    ```

    This line builds the `gameboy` program from the `src/main.c` source file.

4. **Return Program**:

    ```py
    Return("program")
    ```

    This line returns the built program to the calling script.

### Component SConscript Files

Each component has its own SConscript file that defines how to build it. For example, here are the key parts of the `game` component SConscript files:

#### `components/game/Sconscript`

1. **Import Environment**:

    ```py
    Import("env")
    ```

2. **Include dependant Components**:

    ```py
    SConscript('../../components/ui/Sconscript', exports='env')
    ```

3. **Set Include Path**:

    ```py
    env.AppendUnique(CPPPATH=[Path("include").resolve()])
    ```

4. **Build Library**:

    ```py
    env.Library(target="game", source=["src/game.c"])
    ```

5. **Add Library to Environment**:

    ```py
    env.AppendUnique(LIBS=["game"], LIBPATH=[Path.cwd()])
    ```

These SConscript files define how to build each component and add them to the build environment. The main `Sconstruct` file orchestrates the build process by including these SConscript files and setting up the build environment.
