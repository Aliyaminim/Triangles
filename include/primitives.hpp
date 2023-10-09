/*
Нам понадобятся:
• Структуры для двумерной точки, отрезка, треугольника, полигона.
• Важный инсайт: координаты лучше сразу закладывать FP.
• Это будут типы в нашей программе.
• Выделим операции над объектами этих типов.
• Пересечение отрезков, взаимоположение точки и отрезка, построение
полигона как выпуклой оболочки множества точек, вычисление площади
полигона, вероятно что-то ещё....
• Это будут методы классов
*/
#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <array>
#include "floatcompar.hpp"

//#define inter_area_width 100.0

class Point_t {
public:
    float x = NAN, y = NAN, z = NAN;

    //constructor
    explicit Point_t(float x_, float y_, float z_): x(x_), y(y_), z(z_) {} 
    Point_t() = default;

    //operator = default

    bool valid() const { return !(std::isnan(x) || std::isnan(y) || std::isnan(z)); }

    bool equal (const Point_t &rhs) const {
        assert(valid() && rhs.valid());
        
        if (float_comparator(x, rhs.x) != 0)
            return false;
        else if (float_comparator(y, rhs.y) != 0)
            return false;
        else if (float_comparator(z, rhs.z) != 0)
            return false;
        else
            return true;
    }

    void print() const { std::cout << "(" << x << " ; " << y << " ; " << z << ")"; }
};

class Line_t {
    Point_t r0;
    std::array<float, 3> drc_vec;

public:
    //constructor, is line direction strict, copy of point_t, 
    explicit Line_t(const Point_t &p1, const Point_t &p2): r0(p1) {
        drc_vec[0] = p2.x - p1.x;
        drc_vec[1] = p2.y - p1.y;
        drc_vec[2] = p2.z - p1.z;
    } 

    bool valid() const {
        return r0.valid() && !(std::isnan(drc_vec[0]) || std::isnan(drc_vec[1]) 
                               || std::isnan(drc_vec[2]));
    }
};

class Triangle_t {
    void getNormal(const Point_t &v1_, const Point_t &v2_, const Point_t &v3_) {
        float vec12[3] = {v2_.x - v1.x, v2_.y - v1_.y, v2_.z - v1_.z}; 
        float vec13[3] = {v3_.x - v1.x, v3_.y - v1_.y, v3_.z - v1_.z}; 
        float normal_[3];

        //vec12 x vec13
        normal_[0] = vec12[1]*vec13[2] - vec12[2]*vec13[1];
        normal_[1] = vec12[2]*vec13[0] - vec12[0]*vec13[2];
        normal_[2] = vec12[0]*vec13[1] - vec12[1]*vec13[0];
        float len = std::hypot(normal[0], normal[1], normal[2]);

        for (int i = 0; i < 3; ++i) 
            normal[i] = normal_[i] / len;
    }
public:
    Point_t v1, v2, v3; 
    std::array<float, 3> normal;

    //constructor
    explicit Triangle_t(const Point_t &v1_, const Point_t &v2_, const Point_t &v3_) : v1(v1_), v2(v2_),
                                                                             v3(v3_) {       
        getNormal(v1_, v2_, v3_);
    }

    bool valid() const { return (v1.valid() && v2.valid() && v3.valid());}
};