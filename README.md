# C Raytracer

A simple raytracer written in pure C. Inspired by *Ray tracing in One Weekend*.
Outputs rendered images as binary `.ppm` files.

---

## Overview

The main goal of this project is to reimplement and expand on the concepts covered in *Raytracing in One Weekend*.

Additionally, I would like to the following:
- Implement everything in pure C 
- Add a sort of triangle ray collission algorithm
- Accelerate with CUDA where possible

I would like to be able to the ability to read a .stl file, but that's a future project I'm not sure I'll have time for.

I don't currently have any plans to implement any true graphics programming such as OpenGL or Vulkan.


## Building and Running

Make sure you have `make` and `gcc` installed. 

Simply run `make`.

This will:
- Compile all source files in `src/`
- Place object files in `build/`
- Create an executable called `raytracer`

To clean up compiled files, run `make clean`.

After compiling, run `./raytracer`. You will get an output file called `output.ppm` which can be viewed on linux with `feh output.ppm &` or can be converted to .png with `magick output.ppm output.png`.

## Thanks to the following sites:

Raytracing in One Weekend:
https://raytracing.github.io/books/RayTracingInOneWeekend.html

Scatch a Pixel's Triangle rendering site:
https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/why-are-triangles-useful.html
