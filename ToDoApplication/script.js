function addNewTask(text) {
	const taskElement = document.createElement('div');
	const textNode = document.createTextNode(text);
	const removeButton = document.createElement('button');
	taskElement.setAttribute('id', text);
	taskElement.appendChild(textNode);
	taskElement.appendChild(removeButton);
	const documentElement = document.getElementById('content');
	documentElement.appendChild(taskElement);
	removeButton.addEventListener('click', removeTask);
	removeButton.setAttribute('value', text);
	removeButton.textContent = 'Remove Task';
}

function removeTask(event) {
	document.getElementById(event.target.value).remove();
}

function addTask() {
	let text;
	let task = prompt('Please enter a task:', 'Do the Dishes');
	if (task == null || task == '') {
		return;
	} else {
		text = task;
		addNewTask(text);
	}
}
