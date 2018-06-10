module main() {
	difference() {
		union() {
			translate([0, 0, (50/2)-5])
				cube([130, 130, 50], center = true);
		}

		translate([0, 0, (45/2)])
			cube([120, 120, 45], center = true);

		// Motor Mount
		for(th = [0:90:270])
			rotate([0, 0, th])
				translate([50, 0, 42/2])
					rotate([0, 90, 0]) {
						cylinder(d = 23, h = 100, center = true);
						for(x = [-31/2, 31/2])
							for(y = [-31/2, 31/2])
								translate([x, y])
									cylinder(d = 3, h = 100, center = true);
					}

		// Grid
		for(x = [-60, 60])
			for(y = [-60:10:60])
				for(z = [0:10:40])
					translate([x, y, z])
						rotate([0, 90, 0])
							cylinder(d = 3, h = 10, center = true);
		for(x = [-60:10:60])
			for(y = [-60, 60])
				for(z = [0:10:40])
					translate([x, y, z])
						rotate([90, 0, 0])
							cylinder(d = 3, h = 10, center = true, $fn=8);
		for(x = [-60:10:60])
			for(y = [-60:10:60])
				translate([x, y, 0])
					cylinder(d = 3, h = 10, center = true);

		for(x = [-40:40:40])
			for(y = [-40:40:40])
				translate([x, y, 0])
					cylinder(d = 12, h = 10, center = true);

		for(x = [-60, 60])
			for(y = [-40:40:40])
				translate([x, y, 20])
					rotate([0, 90, 0])
						cylinder(d = 12, h = 10, center = true);
		for(x = [-40:40:40])
			for(y = [-60, 60])
				translate([x, y, 20])
					rotate([90, 0, 0])
						cylinder(d = 12, h = 10, center = true, $fn=8);
	}
}

module wheelGuard() {
	difference() {
		union() {
			translate([0, 0, (50/2)-5])
				difference() {
					cube([50, 130, 50], center = true);
					translate([0, 0, -5])
						cube([40, 120, 50], center = true);
				}
		}

		// Wheel Well
		translate([-25, 0, 42/2])
			rotate([0, 90, 0])
				cylinder(d = 75, h = 45);

		// Grid
		for(y = [-60:10:60])
			for(z = [0:10:40])
				translate([25, y, z])
					rotate([0, -90, 0])
						cylinder(d = 3, h = 10);
		for(x = [-20:10:20])
			for(y = [-60, -50, -40, 40, 50, 60])
				translate([x, y, 35])
					cylinder(d = 3, h = 10);
	}
}

main();
//translate([50/2+130/2+5, 0])
//	wheelGuard();
