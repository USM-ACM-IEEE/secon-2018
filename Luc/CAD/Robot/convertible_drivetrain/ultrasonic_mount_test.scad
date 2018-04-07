module main() {
	difference() {
		translate([0, 0, 15/2])
			cube([55, 30, 15], center = true);

		translate([0, 0, 15/2 + 5 + 7])
			cube([45, 21, 15], center = true);
		translate([0, 0, 7/2 + 5])
			cube([42, 21, 7], center = true);

		for(x = [-26/2, 26/2])
			translate([x, 0, 0])
				cylinder(d = 17, h = 5);
	}

	cylinder(d = 8, h = 12);
}
main();
