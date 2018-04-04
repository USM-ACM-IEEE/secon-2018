module main() {
	difference() {
		union() {
			translate([0, 0, 10-5])
			cube([110, 160, 20], center = true);
		}

		translate([0, 0, 7.5])
			cube([100, 150, 15], center = true);

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
		for(x = [-50, 50])
			for(y = [-75:10:75])
				for(z = [0:10:30])
					translate([x, y, 42/2 - 20 + z])
						rotate([0, 90, 0])
							cylinder(d = 3, h = 10, center = true);
		for(x = [-50:10:50])
			for(y = [-75, 75])
				for(z = [0:10:30])
					translate([x, y, 42/2 - 20 + z])
						rotate([90, 0, 0])
							cylinder(d = 3, h = 10, center = true);
		for(x = [-50:10:50])
			for(y = [-75:10:75])
				translate([x, y, 0])
					cylinder(d = 3, h = 10, center = true);
	}
}

main();
