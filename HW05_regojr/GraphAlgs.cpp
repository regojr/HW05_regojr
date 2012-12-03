#include "GraphAlgs.h"
#include <vector>


int			graph_size,
			start;
NodeID*		the_path;
NodeID*		good_route;

EdgeWeight	shortest_route;
Graph*		graph;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	route_holder = G;
	graph_size = G->size();


	getBestTour( the_path, graph_size, start );
	shortest_route = getTourLength( good_route, graph_size );


	std::vector<NodeID> best_route;						// vector to hold sequence of best route
	for( int index = 0; index <= graph_size; index++ )
		best_route.push_back( good_route[index] );		// inserting values from the best calculated route into vector

	std::pair<std::vector<NodeID>, EdgeWeight> pair ( best_route, shortest_route);

	return pair; // pair, first element = vector length n listing the order of the nodes in the cycle (do NOT list the start node twice), 
				 // and the second element = length of that path (do NOT forget to include the edge from the last node back to the start) 
}



void getBestTour( NodeID* sequence, int size, int s )
{

}


EdgeWeight getTourLength( NodeID* tour, int tour_stops )
{
	EdgeWeight tour_length = graph->weight(tour[tour_stops-1], tour[0] );	// set initial length to distance from last to first location
	
	for( int i = 0; i < tour_stops-1; i++ ) {
		tour_length += graph->weight( tour[i], tour[i+1] );		// loops through each edge and adds the distance between each
	}

	return tour_length;
}

