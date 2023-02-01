import { useRef } from "react";

import Card from "../UI/Card";
import classes from "./NewMeetupForm.module.css";

function NewMeetupForm(props) {
	// Create a dictionary of references to the input elements
	const inputRefs = {
		title: useRef(),
		image: useRef(),
		address: useRef(),
		description: useRef(),
	};

	function submitHandler(event) {
		event.preventDefault();

		// Get the values from the input elements
		// const inputValues = {};
		// for (const key in inputRefs) {
		// 	inputValues[key] = inputRefs[key].current.value;
		// }
		const inputValues = Object.fromEntries(
			Object.entries(inputRefs).map(([key, value]) => [
				key,
				value.current.value,
			])
		);

		props.OnAddMeetup(inputValues);
	}

	return (
		<Card>
			<form className={classes.form}>
				<div className={classes.control}>
					<label htmlFor="title">Meetup Title</label>
					<input type="text" required id="title" ref={inputRefs.title} />
				</div>

				<div className={classes.control}>
					<label htmlFor="image">Meetup Image</label>
					<input type="url" required id="image" ref={inputRefs.image} />
				</div>

				<div className={classes.control}>
					<label htmlFor="address">Address</label>
					<input type="text" required id="address" ref={inputRefs.address} />
				</div>

				<div className={classes.control}>
					<label htmlFor="description">Description</label>
					<textarea
						id="description"
						required
						rows="5"
						ref={inputRefs.description}
					/>
				</div>

				<div className={classes.actions}>
					<button onClick={submitHandler}>Add Meetup</button>
				</div>
			</form>
		</Card>
	);
}

export default NewMeetupForm;
