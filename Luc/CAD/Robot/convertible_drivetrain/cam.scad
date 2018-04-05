mult = 0.11111111;
start = 10;

difference() {
	translate([0, 0, -2.5])
		union() {
			for(th = [0:1:179]) {
				hull() {
					rotate([0,0,th])
						cube([mult*th+start, 0.01, 5]);
					rotate([0,0,th+1])
						cube([mult*(th+1)+start, 0.01, 5]);
				}
				mirror([0, 1, 0])
				hull() {
					rotate([0,0,th])
						cube([mult*th+start, 0.01, 5]);
					rotate([0,0,th+1])
						cube([mult*(th+1)+start, 0.01, 5]);
				}
			}
		}

	for(y = [-1, 1])
		translate([0, y*4.5, 0])
			cube([10.5, 1.5, 5], center = true);

	cylinder(d = 3, h = 5, center = true);
}
