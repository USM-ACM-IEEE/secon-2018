module main() {
	difference() {
		union() {
			for(x = [-1, 1])
				translate([x*(30/2 + 35), 30/2, 10/2])
					cube([30, 30, 10], center = true);
			translate([0, 30/2, 10/2 + 10])
				cube([90, 30, 10], center = true);
		}

		// Grid
		for(y = [5:10:25]) {
			for(x = [-60:10:-50])
				translate([x, y]) {
					cylinder(d = 3, h = 10);
					translate([0, 0, 5])
						cylinder(d = 7, h = 5);
				}
			for(x = [50:10:60])
				translate([x, y]) {
					cylinder(d = 3, h = 10);
					translate([0, 0, 5])
						cylinder(d = 7, h = 5);
				}
		}

		for(x = [-40:10:40]) {
			translate([x, 0, 15])
				rotate([-90, 0, 0])
					cylinder(d = 3, h = 10);
			for(y = [5:10:25])
				translate([x, y, 10])
					cylinder(d = 3, h = 10);
		}

		for(x = [-30:10:30])
			for(y = [5:10:25])
				translate([x, y, 5])
					cylinder(d = 3, h = 5);

		for(z = [5]) {
			for(x = [-60:10:-40])
				translate([x, 0, z])
					rotate([-90, 0, 0])
						cylinder(d = 3, h = 5);
			for(x = [40:10:60])
				translate([x, 0, z])
					rotate([-90, 0, 0])
						cylinder(d = 3, h = 5);
		}
	}
}

main();
