#ifndef SHORTESTPATH_MENU_H
#define SHORTESTPATH_MENU_H

#include "graphHandler.h"

/**
 * Function to free the graph entirely
 * @param graph to be free
 */
void freeGraph(GRAPH* graph);

/**
 * Function to load the graph selected based on  the user integer
 * @param number  the integer representing the graph selected
 * @return the graph updated
 */
GRAPH* choose_graph(int number);

/**
 * Function to display guidlines
 * @param step integer representing at what process we are in the graph processing
 * @param graph the graph that will be updated
 * @return the graph updated
 */
GRAPH* displayguidlines(int* step, GRAPH* graph);

#endif //SHORTESTPATH_MENU_H