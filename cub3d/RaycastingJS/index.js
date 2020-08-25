function Player(x, y, direction) {
  this.x = x;
  this.y = y;
  this.direction = direction;
}

function Map(size) {
  this.size = size;
  this.wallGrid = new Uint8Array(size * size);
}

var x = column / this.resolution - 0.5;
var angle = Math.atan2(x, this.focalLength);
var ray = map.cast(player, player.direction + angle, this.range);

function ray(origin) {
  var stepX = step(sin, cos, origin.x, origin.y);
  var stepY = step(cos, sin, origin.y, origin.x, true);
  var nextStep =
    stepX.length2 < stepY.length2
      ? inspect(stepX, 1, 0, origin.distance, stepX.y)
      : inspect(stepY, 0, 1, origin.distance, stepY.x);

  if (nextStep.distance > range) return [origin];
  return [origin].concat(ray(nextStep));
}

var dx = run > 0 ? Math.floor(x + 1) - x : Math.ceil(x - 1) - x;
var dy = dx * (rise / run);

var z = distance * Math.cos(angle);
var wallHeight = (this.height * height) / z;

Camera.prototype.render = function (player, map) {
  this.drawSky(player.direction, map.skybox, map.light);
  this.drawColumns(player, map);
  this.drawWeapon(player.weapon, player.paces);
};
