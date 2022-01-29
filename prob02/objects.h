// Name: Joseph Eggers
// CWID: 885929488
// Email: joseph.eggers@csu.fullerton.edu

// Implement your Object classes here.

#ifndef OBJECTS_H
#define OBJECTS_H

#include "cpputils/graphics/image.h"

class SolidObject {
 private:
  int width_;
  int height_;
  int x_;
  int y_;
  graphics::Image* image_;

 protected:
  // Getter
  graphics::Image* GetImage() const { return image_; };

 public:
  // Constructor
  SolidObject(int width, int height, graphics::Image* image);

  // Getters
  int GetWidth() const { return width_; };
  int GetHeight() const { return height_; };
  int GetX() const { return x_; };
  int GetY() const { return y_; };

  // Setters
  void SetX(int x) { this->x_ = x; };
  void SetY(int y) { this->y_ = y; };

  // virtual function
  virtual void Draw() = 0;

  // functions
  bool CollidesWith(const SolidObject* obj1) const;
};

class Brick : public SolidObject {
 protected:
  graphics::Color color_;

 public:
  // Constructors
  Brick(int width, int height, graphics::Color color, graphics::Image* image);
  Brick(int width, int height, graphics::Image* image);

  // Functions
  void Draw() override;
};

class Paddle : public Brick {
 public:
  // Constructor
  Paddle(int width, int height, graphics::Image* image);
};

class Ball : public SolidObject {
 public:
  // Constructor
  Ball(int diameter, graphics::Image* image);

  // Functions
  void Draw() override;
};
#endif  // OBJECTS_H
