WrOBOT Prototype Sprint 3, Team J, membership to be assigned

LARK_bot is a line following robot program that depends on 2 sensors.  One called "center" which is meant to be placed inside
the line and one called "right" which is meant to set to the right of the line. The program attempts to follow the edge.

LARK_inside_line is another line folling program. It also depends on 2 sensors, one called "left" and one called "right".  These sensors are meant to be side by side.  They should both be placed within a dark line that they are to follow.
If one or the other sensor sees lighter surface, the robot turns away from that side. If it overshoots and both sensors see "light" then it backs up and tries to turn towards the side that last saw dark.

