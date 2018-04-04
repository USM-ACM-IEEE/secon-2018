difference() {
	union() {
		cube([65, 57, 17.5], center = true);
		hull() {
			translate([0, 57/2 - 10/2, 12.5/2])
				cube([65, 10, 17.5 + 12.5], center = true);
			//translate([0, 57/2 - 5/2 - 15, 0])
			//	cube([65, 5, 5], center = true);
		}
	}

	for(x = [-25, 25])
		translate([x, 12.5 - 57/2, 0])
			cylinder(d = 4, h = 17.5, center = true);
	translate([0, 12.5 - 57/2 + 5, 0])
		cylinder(d = 4, h = 17.5, center = true);

	for(x = [-12.5, 12.5])
		translate([x, 0, 17.5/2 + 12.5 - 5])
			rotate([90, 0, 0])
				cylinder(d = 3, h = 100, center = true);

	translate([0, 10-0.25, 17.5/2 + 12.5/2 - 5 - 1])
		cube([65, 17.5, 12.5], center = true);
}
