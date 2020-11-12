#pragma once
class Node
{
private:
	int lowerBound;
	int vertexNumber;
public:
	Node(int vertex, int lower_bound);
	Node();
	~Node();
	int getVertex();
	int getLowerBound();
	void setVertex(int vertex);
	void setLowerBound(int lower_bound);
	bool greatherThan(Node& node);
	bool LesserThan(Node& node);
	bool equal(Node& node);

	class CompareLowerBounds {
	public:
		bool operator()(Node const& n1, Node const& n2) {
			return n1.lowerBound < n2.lowerBound;
		}
	};
};

