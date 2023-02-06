function AboutUs() {
	return (
		<div className="background flex flex-col justify-between h-screen w-full">
			<div className="flex justify-center">
				<div className="py-10 px-10 text-center w-[50%]">
					<h1 className="text-5xl py-2 font-extrabold">About Us</h1>
					<p className="text-2xl py-2">
						Design 6 is a team of three dynamic and talented individuals who
						have come together to deliver exceptional design solutions. Our team
						consists of Sarah, Matthew, and Ryan, who bring unique skills and
						experiences to the table.
					</p>
				</div>
			</div>

			<div className="flex items-center flex-col">
				<img
					src="https://cdn.discordapp.com/attachments/1018300243512664155/1070958477406654514/Mountains-transformed.png"
					className="scaletofit h-full w-full"
				/>
			</div>
		</div>
	);
}

export default AboutUs;
