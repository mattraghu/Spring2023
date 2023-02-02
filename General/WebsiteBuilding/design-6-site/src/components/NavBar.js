// Create a nav bar based on an items list

function NavBar(props) {
	// Create a nav bar based on an items list
	// props = {items: items}
	// items = [{link: link, text: text}, ...]
	function NavBarElement(section) {
		// Create a nav bar element for the item
		// item = {link: link, text: text}
		return <li className="nav-item">{section.text}</li>;
	}

	return (
		<ul className="px-10 py-10 flex justify-contet space-x-8">
			{/* Website Logo */}
			<li className="mr-96">Design 6 Project</li>
			{props.sections.map((item) => {
				return NavBarElement(item);
			})}
		</ul>
	);
}

export default NavBar;
