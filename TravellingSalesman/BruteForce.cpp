#include "BruteForce.h"

#include <iostream>
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

BruteForce::BruteForce() {};
BruteForce::~BruteForce() {};

BruteForce::BruteForce(Graph g) {

	graph = g;
	wasVisited = new bool[graph.getVerteciesAmount()];
	//std::cout <<"[4][1]: "<< graph.getGraphMatrix()[4][1]<<endl;
	for (int i = 0; i < graph.getVerteciesAmount(); ++i) {
		wasVisited[i] = false;
		//cout << wasVisited[i];
	}
	tmpDistance = 0;
	totalDistance = INT_MAX;
}

bool BruteForce::recursiveBruteForce(int vertex) {
	tmpPath.push(vertex);
	if (tmpPath.size() != graph.getVerteciesAmount()) {
		wasVisited[vertex] = true;
		for (int child = 0; child < graph.getVerteciesAmount(); ++child) {
			if (wasVisited[child]) {
				continue;
			}
			tmpDistance += graph.getGraphMatrix()[vertex][child];
			recursiveBruteForce(child);
			tmpDistance -= graph.getGraphMatrix()[vertex][child];
		}
		wasVisited[vertex] = false;
		tmpPath.pop();
	}
	else if (graph.getGraphMatrix()[vertex][0]<=0) {

		tmpPath.pop();

	}else {
		tmpDistance += graph.getGraphMatrix()[vertex][0];
		
		if (tmpDistance >= totalDistance) {
			tmpDistance -= graph.getGraphMatrix()[vertex][0];
		}
		
		else {
			totalDistance = tmpDistance;
			path = tmpPath;
			tmpDistance -= graph.getGraphMatrix()[vertex][0];
		}

		tmpPath.pop();

	}
	if (tmpPath.size()) return true;
	else return false;

}

void BruteForce::displayPath() {
	cout << path <<endl;
}