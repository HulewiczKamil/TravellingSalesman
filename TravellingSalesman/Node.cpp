#include "Node.h"
#include <iostream>

Node::Node(int vertex, int lower_bound) {
	this->vertexNumber = vertex;
	this->lowerBound = lower_bound;
}

Node::~Node() {

}
Node::Node() {
	this->vertexNumber = 0;
	this->lowerBound = INT_MAX;
}
void Node::setVertex(int vertex) {
	this->vertexNumber = vertex;
}

int Node::getVertex() {
	return vertexNumber;
}

void Node::setLowerBound(int lower_bound) {
	this->lowerBound = lower_bound;
}

int Node::getLowerBound() {
	return lowerBound;
}

bool Node::greatherThan(Node& node) {
	return this->lowerBound > node.getLowerBound();
}

bool Node::LesserThan(Node& node) {
	return this->lowerBound < node.getLowerBound();
}

bool Node::equal(Node& node) {
	return this->lowerBound == node.getLowerBound();
}