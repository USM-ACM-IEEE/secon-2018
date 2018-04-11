module main() {
	difference() {
		union() {
			translate([0, 50/2, 20/2])
				cube([130, 50, 20], center = true);
		}

		translate([0, 30/2, 10/2 + 10])
			cube([70, 30, 10], center = true);
		translate([0, 50/2, 10/2 + 10+2])
			cube([70, 50, 10], center = true);

		// Grid
		for(y = [5:10:45])
			for(x = [-60, 60])
				translate([x, y])
					cylinder(d = 7, h = 5);

		for(x = [-60:10:60])
			for(z = [5:10:15])
				translate([x, 0, z])
					rotate([-90, 0, 0])
						cylinder(d = 3, h = 10);

		for(x = [-60:10:60])
			for(y = [5:10:45])
				translate([x, y])
					cylinder(d = 3, h = 20);

		// Ultrasonic
		for(x = [-30, 30])
		translate([x, 40, 0]) {
			translate([0, 0, 15/2 + 5 + 7])
				cube([45, 21, 15], center = true);
			translate([0, 0, 7/2 + 5])
				cube([42, 21, 7], center = true);

			for(x = [-26/2, 26/2])
				translate([x, 0, 0])
					cylinder(d = 17, h = 5);
		}
	}
}

main();
