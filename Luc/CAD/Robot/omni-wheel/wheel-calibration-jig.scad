module main() {
	difference() {
		union() {
			cylinder(d = 75, h = 20);
		}

		cylinder(d = 70, h = 20, $fn = 72);
	}
}

main();
