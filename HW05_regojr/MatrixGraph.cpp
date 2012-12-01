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

}
  
/* inspector */
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	
}

/* inspector */
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
{

}

/* inspector */
unsigned MatrixGraph::degree(NodeID u) const
{

}

/* inspector */
unsigned MatrixGraph::size() const
{

}

/* inspector */
unsigned MatrixGraph::numEdges() const
{

}

