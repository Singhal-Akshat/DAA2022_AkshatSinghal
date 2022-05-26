/*
funnx dijkstra(G,S):
	for each vertex V in G
	dist[v] = INF
	previous[v] = NULL
	
	if v!=s , add V to Quueue Q
	DIST[s] =0
	
	WHILE q IS NOT EMPTY
		U <- EXTRACT MIN FROM q
		for each visited neighbour v of u
		tempDist == dist[u] + w
		
		if templist < dist[v]
			dist[v] = tempdist
			previous[v] = u
		return dist[], previous[]
