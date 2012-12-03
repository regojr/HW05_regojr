#include "ListGraph.h"

using namespace std;

/* Constructor */
ListGraph::ListGraph(int numNodes)
{
	num_edges = 0;
	edgeList.resize(numNodes);
}

/* Destructor */
ListGraph::~ListGraph()
{
}

/* modifier */ 
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	bool match_found = false;
	EList::iterator iter;

	for( iter = edgeList[u].begin(); iter != edgeList[u].end(); iter++)
	{
		NWPair theEdge = *iter;
		if( theEdge.first == v )	// checks if there is already an edge
			match_found = true;
	}

	if( match_found == false ) {	// if there is no match found, add the edge to lists
		edgeList[v].push_front( NWPair( u, weight ) );
		edgeList[u].push_front( NWPair( v, weight ) );
	}
	
}
  
/* inspector - CODE BASE FROM CLASS DISCUSSION */
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const 
{
	edgeList[u];
	EList::const_iterator it;

	for( it = edgeList[u].begin(); it != edgeList[u].end(); it++ ) 
	{
		NWPair theEdge = *it;
		if( theEdge.first == v )
			return theEdge.second;
	}
	return 0.0;
}

/* inspector */
std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	std::list<NWPair> pairList;	// stores values adjacent to u
	pairList = edgeList[u];		// gives list adjacent values 
	return pairList;
}

/* inspector */
unsigned ListGraph::degree(NodeID u) const
{
	unsigned edgeCount = 0;
	EList::const_iterator iter;
	iter = edgeList[u].begin();
	while( iter != edgeList[u].end() ) {
		edgeCount++;
	}

	return edgeCount;
}

/* inspector */
unsigned ListGraph::size() const
{
	return edgeList.size();
}

/* inspector */
unsigned ListGraph::numEdges() const
{
	return num_edges;
}