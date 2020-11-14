#include "BranchAndBoundv2.h"
#include <iostream>
#include <stack>
#include <queue>
#include <ostream>
#include <algorithm>

template <class Container, class Stream>
Stream& printOneValueContainer
(Stream& outputstream, const Container& container)
{
	typename Container::const_iterator beg = container.begin();

	outputstream << "[";

	while (beg != container.end())
	{
		outputstream << " " << *beg++;
	}

	outputstream << " ]";

	return outputstream;
}

template < class Type, class Container >
const Container& container
(const std::stack<Type, Container>& stack)
{
	struct HackedStack : private std::stack<Type, Container>
	{
		static const Container& container
		(const std::stack<Type, Container>& stack)
		{
			return stack.* & HackedStack::c;
		}
	};

	return HackedStack::container(stack);
}

template < class Type, class Container >
const Container& container
(const std::queue<Type, Container>& queue)
{
	struct HackedQueue : private std::queue<Type, Container>
	{
		static const Container& container
		(const std::queue<Type, Container>& queue)
		{
			return queue.* & HackedQueue::c;
		}
	};

	return HackedQueue::container(queue);
}

template
< class Type
	, template <class Type, class Container = std::deque<Type> > class Adapter
	, class Stream
>
Stream& operator<<
(Stream& outputstream, const Adapter<Type>& adapter)
{
	return printOneValueContainer(outputstream, container(adapter));
}


using namespace std;

BranchAndBoundv2::BranchAndBoundv2(Graph g) {
	graph = g;
	pathToAdjustingCities = new int[graph.getVerteciesAmount()];
	wasVisited = new bool[graph.getVerteciesAmount()];

	for (int i = 0; i < graph.getVerteciesAmount(); ++i) {
		wasVisited[i] = false;
	}

	upperBound = INT_MAX;
	int temporaryMinimalValue = INT_MAX;
	tmpDistance = 0;
	initialLowerBound = 0;


	for (int row = 0; row < graph.getVerteciesAmount(); ++row) {

		for (int column = 0; column < graph.getVerteciesAmount(); ++column) {

			if (graph.getGraphMatrix()[row][column] < temporaryMinimalValue) {
				temporaryMinimalValue = graph.getGraphMatrix()[row][column];
			}
		}

		pathToAdjustingCities[row] = temporaryMinimalValue;
		initialLowerBound += temporaryMinimalValue;
		temporaryMinimalValue = INT_MAX;
	}

}

BranchAndBoundv2::~BranchAndBoundv2() {};

void BranchAndBoundv2::run() {
	Node zero = Node(0, initialLowerBound);
	recursiveBnB(zero);
};

void BranchAndBoundv2::recursiveBnB(Node node) {
	tmpPath.push(node.getVertex());
	wasVisited[node.getVertex()] = true;
	Node tmpNode;
	priority_queue<Node, vector<Node>, Node::CompareLowerBounds> bounds;

	for (int child = 0; child < graph.getVerteciesAmount(); ++child) {
		if (!wasVisited[child]) {
			Node n = Node(child, resolveLowerBound(node, child));
			bounds.push(n);
		}
	}

	if (bounds.empty()) {
		if (resolveLowerBound(node, 0) < upperBound) {
			upperBound = resolveLowerBound(node, 0);
			path = tmpPath;
		}

	}
	else {
		while (!bounds.empty())
		{
			tmpNode = bounds.top();
			bounds.pop();
			if (tmpNode.getLowerBound() < upperBound) {
				recursiveBnB(tmpNode);
			}
			else break;
		}
	}
	tmpPath.pop();
	wasVisited[node.getVertex()] = false;
	//Node temp;
	//temp = bounds.top();
	//bounds.pop();
	//if(bounds.empty())
	//cout <<"Index: "<< temp.getVertex()<<" ---- LowerBound: "<<temp.getLowerBound()<<endl;

	/*for (int i = 0; i < graph.getVerteciesAmount(); ++i) {
		if (!wasVisited[i]) {
			n.setVertex(i);
			bounds.push(n);
		}
	}
	while (!bounds.empty())
	{
		n = bounds.top();
		cout << "[Node number]: " << n.getVertex() << " --- [lowerBound]: " << n.getLowerBound() << endl;
		bounds.pop();
	}
	n = bounds.top();
	cout << n.getVertex();*/
	/*cout << node.getVertex() << endl;
	cout << node.getLowerBound() << endl;
	return 999999;*/
}

int BranchAndBoundv2::resolveLowerBound(Node node, int nextCity) {
	int lowerBound = node.getLowerBound();
	lowerBound -= pathToAdjustingCities[node.getVertex()];
	lowerBound += graph.getGraphMatrix()[node.getVertex()][nextCity];
	return lowerBound;
}

void BranchAndBoundv2::displayPath() {
	cout << path << endl;
	cout << "Distance: " << upperBound << endl;
	/*stack <int> path2;
	path2 = path;
	int totalDistance = 0;
	for (int i = 0; i < path.size()-1;i++) {
		int k = path2.top();
		path2.pop();
		totalDistance += graph.getGraphMatrix()[k][path2.top()];
	}
	cout << "[Total Distance]: " << totalDistance << endl;
	cout << "Path size: " << path.size() << endl;*/

};