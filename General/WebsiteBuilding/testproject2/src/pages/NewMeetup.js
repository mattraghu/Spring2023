import { useNavigate } from "react-router-dom";
import NewMeetupForm from "../components/meetups/NewMeetupForm";

function NewMeetupPage() {
	const navigate = useNavigate();
	function AddMeetupHandler(meetupData) {
		fetch(
			"https://testproject2-3faef-default-rtdb.firebaseio.com/meetups.json",
			{
				method: "POST",
				body: JSON.stringify(meetupData),
				headers: {
					"Content-Type": "application/json", // Make sure the data is in JSON format
				},
			}
		).then(() => {
			navigate("/", { replace: true });
		});
	}

	return (
		<div>
			<h1>New Meetup Page</h1>
			<NewMeetupForm OnAddMeetup={AddMeetupHandler} />
		</div>
	);
}

export default NewMeetupPage;
