/*
    This file is part of the mydraw.

    mydraw is a simple, interactive drawing program written using OpenGL. 
    
    This code base is meant to serve as a starter code for an assignment in a 
    Computer Graphics course.

    Copyright (c) 2018 by Parag Chaudhuri

    mydraw is free software; you can redistribute it and/or modify it under the 
    terms of the MIT License.

    Permission is hereby granted, free of charge, to any person obtaining a copy
        of this software and associated documentation files (the "Software"), to deal
        in the Software without restriction, including without limitation the rights
        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
        copies of the Software, and to permit persons to whom the Software is
        furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included in all
        copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
        IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
        OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
        SOFTWARE.
 */
#include <iostream>
#include "brush.hpp"
#include "canvas.hpp"

namespace mydraw {

    void point_brush_t::stroke(const point_t &pt, canvas_t &canvas) {
        int x, y, newx, newy;
        x = pt.x;
        y = pt.y;
        int curr_size = get_size();
        if (curr_size == 1) {
            canvas.set_pixel(pt);
        } else if (get_size() > 1) {
            for (int i = 0; i < curr_size; i++) {
                for (int j = 0; j < get_size(); j++) {
                    newx = x - curr_size / 2 + i;
                    newy = y - curr_size / 2 + j;
                    if ((newx < (int) canvas.get_width()) &&
                            (newy < (int) canvas.get_height()) &&
                            (newx > 0) &&
                            (newy > 0)) {
                        canvas.set_pixel(newx, newy);
                    }

                }
            }
        }
    }

    void point_brush_t::stroke(unsigned int xpos, unsigned int ypos, canvas_t *canvas) {
        if (get_size() == 1) canvas->set_pixel(xpos, ypos);
    }

    void eraser_point_brush_t::stroke(const point_t &pt, canvas_t &canvas) {
        point_t newpnt;
        int x, y, newx, newy;
        x = pt.x;
        y = pt.y;
        int curr_size = get_size();
        if (curr_size == 1) {
            canvas.erase_pixel(pt);
        } else if (curr_size > 1) {
            for (int i = 0; i < get_size(); i++) {
                for (int j = 0; j < get_size(); j++) {
                    newx = x - curr_size / 2 + i;
                    newy = y - curr_size / 2 + j;
                    if ((newx < (int) canvas.get_width()) &&
                            (newy < (int) canvas.get_height()) &&
                            (newx > 0) &&
                            (newy > 0)) {
                        newpnt.x = newx;
                        newpnt.y = newy;
                        canvas.erase_pixel(newpnt);
                    }
                }
            }
        }
    }

    void eraser_point_brush_t::stroke(unsigned int xpos, unsigned int ypos, canvas_t *canvas) {
        if (get_size() == 1) canvas->set_pixel(xpos, ypos);
    }

}
