const char capabilities[] PROGMEM = R"=====(
const amp = [{ cmd: 'down', name: 'Decrease volume', icon: '' },
  { cmd: 'up', name: 'Increase volume', icon: '' },
  { cmd: 'audio1', name: 'Audio 1', icon: '' },
  { cmd: 'audio2', name: 'Audio 2', icon: '' },
  { cmd: 'av1', name: 'AV 1', icon: '' },
  { cmd: 'av2', name: 'AV 2', icon: '' },
  { cmd: 'av3', name: 'AV 3', icon: '' },
  { cmd: 'av4', name: 'AV 4', icon: '' },
  { cmd: 'hdmi1', name: 'HDMI 1', icon: '' },
  { cmd: 'hdmi2', name: 'HDMI 2', icon: '' },
  { cmd: 'pwrAmp', name: 'Toggle Amp', icon: '' }];

const tv = [{ cmd: 'pwrTv', name: 'Toggle TV' },
  { cmd: 'input1', name: 'Switch' },
  { cmd: 'input2', name: 'Xbone' } ,
  { cmd: 'input3', name: 'Chromecast' },
  { cmd: 'enter', name: 'Enter' }]

const capabilities = { 'amp': amp, 'tv': tv }
)=====";
