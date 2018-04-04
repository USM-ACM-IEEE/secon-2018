module nema17(length) {
	difference() {
		union() {
			// Base
			translate([0, 0, -length/2])
				cube([42.3, 42.3, length], center = true);
	
			// Shaft
			cylinder(d = 5, h = 24);

			// Motor flat
			cylinder(d = 22, h = 2);
		}

		// Mount Holes
		for(x = [-31/2, 31/2])
			for(y = [-31/2, 31/2])
				translate([x,  y, -4.5])
					cylinder(d = 3, h = 4.5);
	}
}

module plus() {
	length = 40;
	for(theta = [0:90:270])
		rotate([0, 0, theta]) {
			// Motor
			//translate([0, length + 43/2, 42/2 + 5]) rotate([-90, 0, 0]) nema17(length = length);

			difference() {
				union() {
					// Base
					translate([-(43)/2, 0, 0])
						cube([43, length + 43/2 + 5, 5]);

					// Motor Ears
					translate([-(43)/2, length + 43/2, 0])
						cube([43, 5, 15]);
				}

				for(x = [-31/2, 31/2])
					translate([x, length + 43/2, 5 + 43/2 - 31/2])
						rotate([-90, 0, 0])
							cylinder(d = 3, h = 5);
			}
		}
}

module square() {
	length = 40;
	for(theta = [0:90:270])
		rotate([0, 0, theta]) {
			// Motor
			//translate([43/2, length, 42/2 + 5]) rotate([-90, 0, 0]) nema17(length = length);

			difference() {
				union() {
					// Base
					translate([0, 0, 0])
						cube([43, length + 5, 5]);

					// Motor Ears
					translate([0, length, 0])
						cube([43, 5, 15]);
				}

				#for(x = [-31/2, 31/2])
					translate([x + 43/2, length, 5 + 43/2 - 31/2])
						rotate([-90, 0, 0])
							cylinder(d = 3, h = 5);
			}
		}
}

square();
