module main() {
	difference() {
		translate([0, -15, 0])
			cube([70, 30, 5]);

		translate([15, 0])
			cylinder(d = 12, h = 5);

		translate([15+20, 17.5/2])
			cylinder(d = 3, h = 5);
		translate([15+20, -17.5/2])
			cylinder(d = 3, h = 5);

		translate([15+20+7.5, -15/2])
			cube([25, 15, 5]);
	}
}

main();
