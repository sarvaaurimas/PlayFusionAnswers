# PlayFusionAnswers

Two source files contain the solutions to part A and part B questions accordingly. For both questions only standart library header files were used.

Part A
The whole part is done by using x and y coordinates as integers as that's how it was specified in the Question 1 but it can all be converted to floats if needed.

Q1 - used Pythagoras theorem to calculate the distances between points

Q2 - overloaded the < operator so the standart library sort algorithm sorts the Point2D objects by their distance from the origin

Q3 - Implemented the given formula for twice signed area in isAntiClockwise and isCollinear functions

Q4 - Used Q3 formula to create doIntersect function that checks if given line segments intersect. It requires a bit more explanation:
Two segments(a1, b1) and (a2, b2) intersect if one of the conditions is passed:
1. General case - (a1, b1, a2) and (a1, b1, b2) have different orientations and (a2, b2, a1) and (a2, b2, b1) have different orientations.
2. Special case - (a1, b1, a2), (a1, b1, b2), (a2, b2, a1), and (a2, b2, b1) are all collinear and the x-projections of (a1, b1) and (a2, b2) intersect and the y-projections of (a1, b1) and (a2, b2) intersect. 

Q5 - Used the function doIntersect from Q4 to create a new function isInside that checks if the given point is inside the specified polygon:
1. The algorithm draws a long imaginary line parallel to the x axis from the specified point.
2. It uses the doIntersect function to check how many times the imaginary line intersects with the polygon edges and if the imaginary line is collinear with any of them.
3. It determines that the point is inside the polygon if the number of intersections is odd or if the point lies on the edge of the polygon.

Part B

Q1 - Used the round robin tournament idea for the match creation. I treated the players as a vector of integers each integer representing a specific player.
I then fixed the first player in the vector and rotated the others in a circle each round. To determine the round pairings I would pair the first player in the vector with the last, the second with the second to last and so on.

Q2 - Outputted the pairings of each round to a .txt file - the pairs are all in format of (int, int) - (1, 7) would mean player 1 plays player 7 that round.

Q3 - Introduced a simple modification - for the first half of the rounds I would put first player on the vector against the last and for the second half I inversed the order and put the last against the first.

Bonus Question - for the odd number of players I introduced a dummy player 0 and put it in the front of the players vector. Then I fixed it and rotated everyone as before, just the person that matched with player 0 would not play that round.

If you require any  additional information please contact me via sarvaaurimas@gmail.com
