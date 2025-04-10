// import p5 from 'p5/lib/p5'

import p5 from 'p5'

const sketch = window
const canvas = document.getElementById("grahamScanCanvas")

const points = []
const hull = []
const maxPoints = 50
const pointsBuffer = 100

let leftMost = undefined
let currentVertex = undefined
let index= undefined
let nextIndex = -1
let nextVertex= undefined

// Create a new p5 instance, passing the canvas element
sketch.setup = () => {
  createCanvas(800, 600, P2D, canvas)

  // Create a random set of points
  for(let i = 0; i < maxPoints; i++ ) {
    points.push(createVector(random(pointsBuffer, width-pointsBuffer), random(pointsBuffer, height-pointsBuffer)))
  }

  // Sort the points by their x coordinate
  points.sort((a, b) => a.x - b.x)

  leftMost = points[0]
  currentVertex = leftMost
  hull.push(currentVertex)
  nextVertex = points[1]
  index = 2
}

sketch.draw = () => {
  background(0)

  stroke(255)
  strokeWeight(5)
  for(const p of points)
    point(p.x, p.y)

  stroke(0, 0, 255)
  fill(0, 0, 255, 50)
  beginShape()
  for (let p of hull) {
    vertex(p.x, p.y)
  }
  endShape(CLOSE)

  stroke(0, 255, 0)
  strokeWeight(32)
  point(leftMost.x, leftMost.y)

  stroke(200, 0, 255)
  strokeWeight(32)
  point(currentVertex.x, currentVertex.y)

  stroke(0, 255, 0)
  strokeWeight(2)
  line(currentVertex.x, currentVertex.y, nextVertex.x, nextVertex.y)

  let checking = points[index]
  stroke(255)
  line(currentVertex.x, currentVertex.y, checking.x, checking.y)

  const a = p5.Vector.sub(nextVertex, currentVertex)
  const b = p5.Vector.sub(checking, currentVertex)
  const cross = a.cross(b)

  if (cross.z < 0) {
    nextVertex = checking
    nextIndex = index
  }

  index = index + 1
  if (index == points.length) {
    if (nextVertex == leftMost) {
      console.log('done')
      noLoop()
    } else {
      hull.push(nextVertex)
      currentVertex = nextVertex
      index = 0
      //points.splice(nextIndex, 1)
      nextVertex = leftMost
    }
  }
}

