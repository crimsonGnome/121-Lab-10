// Name: Joseph Eggers
// CWID: 885929488
// Email: joseph.eggers@csu.fullerton.edu

// Implement your Object classes here.

#include "objects.h"

#include "cpputils/graphics/image.h"

SolidObject::SolidObject(int width, int height, graphics::Image* image) {
  this->width_ = width;
  this->height_ = height;
  this->image_ = image;
}

bool SolidObject::CollidesWith(const SolidObject* obj1) const {
  if (width_ == 0 || height_ == 0 || obj1->GetWidth() == 0 ||
      obj1->GetHeight() == 0) {
    return false;
  }
  if (width_ + x_ >= obj1->GetX() && x_ <= obj1->GetX() + obj1->GetWidth()) {
    if (height_ + y_ >= obj1->GetY() &&
        y_ <= obj1->GetY() + obj1->GetHeight()) {
      return true;
    }
  }
  return false;
}

Brick::Brick(int width, int height, graphics::Color color,
             graphics::Image* image)
    : SolidObject(width, height, image) {
  this->color_ = color;
}

Brick::Brick(int width, int height, graphics::Image* image)
    : SolidObject(width, height, image) {
  graphics::Color color(50, 50, 50);
  this->color_ = color;
}

void Brick::Draw() {
  graphics::Image* image = GetImage();
  image->DrawRectangle(GetX(), GetY(), GetWidth(), GetHeight(), color_);
}

Paddle::Paddle(int width, int height, graphics::Image* image)
    : Brick(width, height, image) {}

Ball::Ball(int diameter, graphics::Image* image)
    : SolidObject(diameter, diameter, image) {}

void Ball::Draw() {
  graphics::Image* image = GetImage();
  int radius = GetHeight() / 2;

  image->DrawCircle(GetX() + radius, GetY() + radius, radius, 210, 25, 25);
}
