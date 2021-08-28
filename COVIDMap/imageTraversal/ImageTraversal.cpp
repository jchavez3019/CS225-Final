#include <cmath>
#include <iterator>
#include <iostream>
#include <vector>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator():traversal_(NULL),current_(Point(0,0)) {
  /** @todo [Part 1] */
}

ImageTraversal::Iterator::Iterator(ImageTraversal * traversal, Point & start, double & tolerance, PNG & image) {
  traversal_ = traversal;
  start_ = start;
  tolerance_ = tolerance;
  image_ = image;
  current_ = traversal_->peek();
  visited_.resize(image.width() * image.height(), false);
}

bool ImageTraversal::Iterator::isVisited_(Point currPoint) {
  return visited_[currPoint.x + currPoint.y * image_.width()];
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  if (!traversal_->empty()) {
    current_ = traversal_->pop();
    visited_[current_.x + current_.y * image_.width()] = true;

   // vector<Point> offset = {Point(1,0),Point(0,1),Point(-1,0),Point(0,-1)};

    Point right_ = Point(current_.x + 1, current_.y);
    Point below_ = Point(current_.x, current_.y + 1);
    Point left_ = Point(current_.x - 1, current_.y);
    Point above_ = Point(current_.x, current_.y - 1);

    while (!traversal_->empty() && isVisited_(Point(traversal_->peek().x, traversal_->peek().y))) 
      current_ = traversal_->pop();
    // for(Point & offsetPoint : offset){
    //   Point temp = Point (current_.x + offsetPoint.x, current_.y + offsetPoint.y);

    //   if(check_(temp))
    //     traversal_->add(temp);
    // }
    if(check_(right_))
      traversal_->add(right_);
    if(check_(below_))
      traversal_->add(below_);
    if(check_(left_))
      traversal_->add(left_);
    if(check_(above_))
      traversal_->add(above_);
  
    }
    if (!traversal_->empty()) 
      current_ = traversal_->peek();
  
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

  bool thisEmpty = false;
  bool otherEmpty = false;

  if (traversal_ == NULL) thisEmpty = true;
  if (other.traversal_ == NULL) otherEmpty = true;

  if (!thisEmpty) 
    thisEmpty = traversal_->empty();
  if (!otherEmpty) 
    otherEmpty = other.traversal_->empty();

  if (thisEmpty && otherEmpty) 
    return false;
  

  return true;

}

bool ImageTraversal::Iterator::check_ (Point currPoint){

if(currPoint.x < image_.width() && currPoint.y < image_.height()){
  HSLAPixel p1 = image_.getPixel(currPoint.x,currPoint.y);
  HSLAPixel p2 = image_.getPixel(start_.x,start_.y);
  double delta = calculateDelta(p1,p2);
  if(delta <= tolerance_){
    if(!isVisited_(currPoint))
      return true;
  }
}
return false;
}



