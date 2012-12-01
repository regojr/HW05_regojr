#include "MatrixGraph.h"

using namespace std;

/* constructor */
MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	num_edges = 0;
	M.resize( num_nodes, std::vector<EdgeWeight>(num_nodes, 0.0) );
}
 
/* destructor */
MatrixGraph::~MatrixGraph()
{
}

  
/* modifier */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	if( u != v ) {  // CITATION: from angless, making sure not to make an edge to itself
		M[u][v] = weight;
		M[v][u] = weight;
		
		num_edges++;
	}
}
  
/* inspector */
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	if( u < 0 || v < 0 || u >= M.size() || v >= M.size() )	// if anything isnot within matrix bounds, 
		return 0.0;											// return 0
	else
		return M[u][v];
}

/* inspector */
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
{
	std::list<NWPair> PairList;
	std::vector<EdgeWeight>::const_iterator iter = M[u].begin();
	int id = 0;

	for( iter = M[u].begin(); iter != M[u].end(); iter++ ) 
	{
		if( *iter != 0.0 )
			PairList.push_front( NWPair( id, *iter ) );
		id++;
	}
	return PairList;
}

/* inspector */
unsigned MatrixGraph::degree(NodeID u) const
{
	unsigned numNeighbs = 0;
	std::vector<EdgeWeight>::const_iterator iter;

	for( iter = M[u].begin(); iter != M[u].end(); iter++ )
	{
		if( *iter != 0 )		// if there is a neighbor, increase counter
			numNeighbs++;
	}

	return numNeighbs;
}

/* inspector */
unsigned MatrixGraph::size() const
{
	return M.size();
}

/* inspector */
unsigned MatrixGraph::numEdges() const
{
	return num_edges;
}

