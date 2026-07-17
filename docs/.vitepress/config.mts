import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  base: '/Coding_Practice/',
  title: "CP Skills",
  description: "A Site To Demonstrate Emmetthor's Coding Skills.",

  markdown: {
    math: true
  },

  head: [
    [
      'script',
      {
        type: 'module',
        src: 'https://static.cloudflareinsights.com/beacon.min.js',
        'data-cf-beacon':
          '{"token":"15e598c9b544431da3fa523ae2830dc3"}'
      }
    ]
  ],

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '首頁', link: '/' },
      { text: '競程介紹', link: '/mindset_and_implementation/index' },
      { text: '解題知識與技巧', link: 'techniques/index'},
      { text: '題解', link: 'problem_solutions/index.md' },
    ],

    sidebar: {
      '/mindset_and_implementation/': [
        {
          text: '競程、心態與策略',
          items: [
            { text: '首頁', link: 'mindset_and_implementation/index' },
            { text: '競賽策略', link: 'mindset_and_implementation/contest_technique' },
            { text: '實作原則', link: 'mindset_and_implementation/implementation_rule' },
          ]
        }
      ],

      '/techniques/': [
        {
          text: '解題知識與技巧',
          items: [
            { text: '首頁', link: '/techniques/index' },

            {
              text: '數學',
              collapsed: true,
              items: [
                { text: '取餘', link: '/techniques/math/modulo' },
                { text: '質數', link: '/techniques/math/prime' },
                { text: '最大公因數與最小公倍數', link: '/techniques/math/gcd_lcm' },
                { text: '組合數', link: '/techniques/math/combinatorics' },
                { text: '等價類計數', link: '/techniques/math/counting_equivalent_states' },
                { text: '數學式化簡', link: '/techniques/math/equation_optimize' },
                { text: '排容原理', link: '/techniques/math/inclusion_exclusion' },
                { text: '中位數', link: '/techniques/math/median' },
                { text: '機率與期望值', link: '/techniques/math/probability_and_expected_value' },
              ]
            },

            {
              text: '序列演算法',
              collapsed: true,
              items: [
                { text: '雙指標', link: '/techniques/sequence_algorithms/two_pointer' },
                { text: '單調隊列', link: '/techniques/sequence_algorithms/monotonic_sequence' },
                { text: '交換問題', link: '/techniques/sequence_algorithms/swap_linked_technique' },
                { text: '微掃描線', link: '/techniques/sequence_algorithms/micro_scan_line'},
              ]
            },

            {
              text: '前綴和與差分',
              collapsed: true,
              items: [
                { text: '前綴和', link: '/techniques/prefix_sum_and_difference/prefix_sum' },
                { text: '差分', link: '/techniques/prefix_sum_and_difference/difference' },
              ]
            },

            {
              text: '二分搜',
              collapsed: true,
              items: [
                { text: '二分搜', link: '/techniques/binary_search/binary_search_introdution' },
                { text: 'lower / upper bound', link: '/techniques/binary_search/lower_bound_and_upper_bound' },
                { text: '三分搜', link: '/techniques/binary_search/ternary_search_introdution' },
              ]
            },

            {
              text: '貪心',
              collapsed: true,
              items: [
                { text: '難找的貪心', link: 'techniques/greedy/hard_to_prove_greedy' },
              ]
            },

            {
              text: '動態規劃',
              collapsed: true,
              items: [
                { text: '動態規劃', link: '/techniques/dp/dp_introduce' },
                { text: '狀態設計', link: '/techniques/dp/dp_state_design' },
                { text: '背包問題', link: '/techniques/dp/knapsack' },
                { text: '分段 dp', link: '/techniques/dp/partition_dp' },
                { text: '二維地圖 dp', link: '/techniques/dp/path_on_grid' },
                { text: '區間 dp', link: '/techniques/dp/range_dp' },
                { text: '樹 dp', link: '/techniques/dp/tree_dp' },
                { text: '加權區間排程 dp', link: '/techniques/dp/weighted_interval_scheduling_dp' },
                { text: '數位 dp', link: '/techniques/dp/digit_dp' },
                { text: '定和賽局', link: '/techniques/dp/constant_sum_game' },
              ]
            },

            {
              text: '圖論',
              collapsed: true,
              items: [
                { text: '圖論建模', link: '/techniques/graph_algorithms/graph_theory_modeling' },
                { text: '找環', link: '/techniques/graph_algorithms/find_cycles' },
                { text: '拓撲排序', link: '/techniques/graph_algorithms/topological_sort' },
              ]
            },

            {
              text: '最短路',
              collapsed: true,
              items: [
                { text: 'Floyd Warshall', link: '/techniques/shortest_path/floyd_warshall' },
                { text: 'Dijkstra', link: '/techniques/shortest_path/dijkstra' },
                { text: 'Bellman Ford', link: '/techniques/shortest_path/bellman_ford' },
              ]
            },

            {
              text: '樹論',
              collapsed: true,
              items: [
                { text: '樹壓平', link: '/techniques/tree/euler_tour_technique' },
                { text: 'LCA', link: '/techniques/tree/LCA' },
              ]
            },

            {
              text: '資料結構',
              collapsed: true,
              items: [
                { text: '線段樹', link: '/techniques/data_structures/segment_tree' },
              ]
            },

            {
              text: '實作',
              collapsed: true,
              items: [
                { text: '回文', link: '/techniques/implementation/palindrome' },
                { text: '正方形網格', link: '/techniques/implementation/square_grid' },
                { text: '六邊形網格', link: '/techniques/implementation/hexagonal_grid' },
              ]
            },
          ]
        }
      ],

      '/problem_solutions/': [
        {
          text: '題解',
          items: [
            { text: '首頁', link: 'problem_solutions/index' },

            {
              text: 'Atcoder Beginner Contest',
              items: [
                { text: 'ABC452E', link: 'problem_solutions/ABC/452/ABC452E' },
                { text: 'ABC455E', link: 'problem_solutions/ABC/455/ABC455E' },
              ]
            },

            {
              text: 'LeetCode',
              items: [
                { text: 'LeetCode2033', link: 'problem_solutions/LeetCode/LeetCode2033' },
              ]
            },
          ]
        }
      ],
    },

    socialLinks: [
      { icon: 'github', link: 'https://github.com/vuejs/vitepress' }
    ],

    lastUpdated: {
      text: 'Updated at',
      formatOptions: {
        dateStyle: 'full',
        timeStyle: 'medium'
      }
    },

    search: {
      provider: 'local'
    }
  }
})
