<script setup>
import { onBeforeUnmount, onMounted, ref } from 'vue'

const props = defineProps({
  src: {
    type: String,
    required: true
  },
  alt: {
    type: String,
    default: ''
  }
})

const stage = ref(null)
const target = ref(null)
let panzoom = null

onMounted(async () => {
  const { default: Panzoom } = await import('@panzoom/panzoom')

  panzoom = Panzoom(target.value, {
    maxScale: 10,
    minScale: 0.1,
    startScale: 0.1,
    contain: 'outside'
  })

  stage.value.addEventListener('wheel', panzoom.zoomWithWheel)
})

onBeforeUnmount(() => {
  if (panzoom && stage.value) {
    stage.value.removeEventListener('wheel', panzoom.zoomWithWheel)
    panzoom.destroy()
  }
})

function zoomIn() {
  panzoom?.zoomIn()
}

function zoomOut() {
  panzoom?.zoomOut()
}

function reset() {
  panzoom?.reset()
}
</script>

<template>
  <div class="svg-viewer">
    <div ref="stage" class="stage">
      <img
        ref="target"
        class="skill-tree"
        :src="src"
        :alt="alt"
        draggable="false"
      >
    </div>
  </div>
</template>

<style scoped>
.svg-viewer {
  border-radius: 8px;
  overflow: hidden;
}

.stage {
  height: 100vh;
  overflow: hidden;
  background: var(--vp-c-bg);
  cursor: grab;
}

.skill-tree {
  max-width: none;
  width: 1600px;
  user-select: none;
}
</style>