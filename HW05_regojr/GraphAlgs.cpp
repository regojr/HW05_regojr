#include "GraphAlgs.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

#include <vector>
using namespace std;

int			graph_size;
int			start;
NodeID*		the_path;
NodeID*		best_path;
EdgeWeight	path_length;
std::vector<NodeID> best_route;		// vector to hold sequence of best route
Graph*		graph;

/* Old method attempting to calculate best tour
void getBestTour( NodeID* sequence, int size, int s )
{	
	EdgeWeight best_path_wt	= getTourLength(best_path, size);
	EdgeWeight this_path_wt = best_path_wt;
	bool stop = false;
	int counter = 0;
	while( !stop ) {
		if( this_path_wt < best_path_wt ) {		// stops loop when better path found
			best_path = sequence;
			stop = true;
		}
		else {									// if not best path, change route to see if shorter can be found
			changeTour(sequence, counter, counter+1);
			counter++;
		}
	}
}
*/





void changeRoute( NodeID* toSwap, int swapTo, int swapFrom )
{
	NodeID nodeHolder	= toSwap[ swapTo ];
	toSwap[ swapTo ]	= toSwap[ swapFrom ];
	toSwap[ swapFrom ]	= nodeHolder;
}


EdgeWeight getTourLength( NodeID* tour, int tour_stops )
{
	EdgeWeight tour_length = graph->weight(tour[tour_stops-1], tour[0] );	// set initial length to distance from last to first location
	
	for( int i = 0; i < tour_stops-1; i++ ) 
	{
		tour_length += graph->weight( tour[i], tour[i+1] );		// loops through each edge and adds the distance between each
	}

	return tour_length;
}

/* CITATION: original idea from angless, also, additional code from class 11/20 lecture*/
void makeTour( NodeID* ids, int size, int s ) 
{
	if( (size - s) == 1 )		// sentinel condition
	{
		if( getTourLength(ids, graph_size) < getTourLength(best_path, graph_size) )		// if ids route is shorter than best_path (so far)
			best_path = ids;															// set best_route to ids
	}
	else																				// if starting pt isnt closes to last val										
	{
		for( int i = s; i < graph_size; i++ ) 
		{
			changeRoute( ids, s, i );				// swap starting pt with current place
			makeTour( ids, size, s+1 );				// make the tour again recursively
			changeRoute( ids, s, i );				// swap values back if not better path
		}
	}
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	
	graph = G;
	graph_size = G->size();
	start = 0;

	/* NodeID* to compare/use for searching */
	the_path  = new NodeID[graph_size];
	best_path = new NodeID[graph_size];

	for(int i=0; i < graph_size; i++ ) {
		the_path[i] = best_path[i] = i;		// set initial node values
	}
		
	makeTour( the_path, graph_size, start );		
	
	/* giving the vector the best path calculated */
	for( int index = 0; index <= graph_size; index++ ) {
		best_route.push_back( best_path[index] );
	}

	path_length = getTourLength(best_path, graph_size);
	std::pair<std::vector<NodeID>, EdgeWeight> NEWpair ( best_route, path_length);

	return NEWpair;	 // pair, first element = vector length n listing the order of the nodes in the cycle (do NOT list the start node twice), 
					 // and the second element = length of that path (do NOT forget to include the edge from the last node back to the start) 
}