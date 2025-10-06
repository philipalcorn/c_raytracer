# C Raytracer

A simple raytracer written in pure C. Inspired by *Ray tracing in One Weeken*.
Outputs rendered images as binary `.ppm` files.

---

## Overview

The goal for this project is to reimplement and expand on the concepts covered in *Raytracing in One Weekend* in pure C. 

## Building and Running

Make sure you have `make` and `gcc` installed. 

Simply run `make`.

This will:
- Compile all source files in `src/`
- Place object files in `build/`
- Create an executable called `raytracer`

To clean up compiled files, run `make clean`.

After compiling, run `./raytracer`. You will get an output file called `output.ppm` which can be viewed on linux with `feh output.ppm` or can be converted to .png with `magick output.ppm output.png`.




