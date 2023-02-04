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
		<div className="TopBarMainContainer px-5 sm:px-10 py-5 flex justify-between">
			<div className="WebsiteLogo flex gap-3 items-center">
				{/* Add Website Logo */}
				<img
					src="https://media.discordapp.net/attachments/1018300243512664155/1070941945498697728/download.jpg"
					alt="Logo"
					className="w-10 h-10 rounded-tl-xl rounded-br-xl"
				/>

				{/* Add Website Name */}
				<span className="text-2xl font-bold">Design 6 Project</span>
			</div>
			<div className="flex gap-3 items-center">
				{props.sections.map((item) => {
					return NavBarElement(item);
				})}

				<div className="block sm:hidden">
					<MenuIcon />
				</div>
			</div>
		</div>
	);
}

export default NavBar;
