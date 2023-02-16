// Create a nav bar based on an items list
import { Link } from "react-router-dom";
import MenuIcon from "./MenuIcon";

function NavBar(props) {
	// Create a nav bar based on an items list
	// props = {items: items}
	// items = [{link: link, text: text}, ...]
	function NavBarElement(section) {
		// Create a nav bar element for the item
		// item = {link: link, text: text}
		return (
			<div className=" px-3 py-2 bg-slate-800 rounded hidden sm:block hover:bg-yellow-600">
				{/* <Link to="/">{section.text}</Link> */}
				<Link to={section.url}>{section.text}</Link>
			</div>
		);
	}
	return (
		<ul className="px-10 py-10 flex justify-content gap-x-8">
			{/* Website Logo */}
			<li className="mr-auto text-2xl font-bold ">Design 6 Project</li>
			{props.sections.map((item) => {
				return NavBarElement(item);
			})}
		</ul>
	);
}

export default NavBar;
