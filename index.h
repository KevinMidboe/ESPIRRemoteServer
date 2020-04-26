const char html[] PROGMEM = R"=====(
<!DOCTYPE html><html>
<head>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <h1>ESP Media controller</h1>
</body>
<script src='capabilities.js'></script>
<script type='application/javascript'>
function draw() {
  const { body } = document;

  Object.keys(capabilities).forEach(key => {
    const heading = document.createElement('h2');
    const container = document.createElement('div');
    container.className = 'container';

    heading.innerText = key;
    container.appendChild(heading)

    capabilities[key].forEach(action => {
      const button = document.createElement('button');
      button.innerText = action.name;
      button.setAttribute('onClick', `toggle('${action.cmd}')`);

      container.appendChild(button);
    })

    container.appendChild(document.createElement('hr'));
    body.appendChild(container)
  });
}

draw();

function toggle(value) {
  window.fetch('http://10.0.0.100/' + value, { method: 'POST' })
  .then(console.log, console.error)
}
</script></html>
)=====";
