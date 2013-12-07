function AssignmentCtrl($scope) {
    $scope.assignments = [

        {led: 10, due: 'Nov 29th', subject: 'Writer Workshop', task: 'Literary Postcards', status: 'missing' },
        {led: 9, due: 'Mon, Dec 9th', subject: 'Science', task: 'definition homework', status: 'in-progress' },
        {led: 8, due: 'not assigned', subject: 'Writer Workshop', task: 'pet peeves', status: 'unassigned' },

        {led: 7, due: 'Mon, Dec 9th', subject: 'History', task: '5 question video', status: 'in-progress' },
        {led: 6, due: 'Mon, Dec 9th', subject: 'Spanish', task: 'art poster', status: 'in-progress' },

        {led: 5, due: 'Thurs, Dec 5th', subject: 'English', task: 'essay ', status: 'completed' },

        {led: 4, due: 'Wed, Dec 3th', subject: 'Science', task: 'bookwork', status: 'completed' },
        {led: 3, due: 'Mon, Dec 2nd', subject: 'History', task: '11/26 margin notes', status: 'completed' },
        {led: 2, due: 'Mon, Dec 2nd', subject: 'Writer Workshop', task: 'Dialog Entry', status: 'completed' },
        {led: 1, due: 'Mon, Dec 2nd', subject: 'Writer Workshop', task: 'Found Poem', status: 'completed' },
        {led: 0, due: 'Mon, Dec 2nd', subject: 'Spanish', task: '11/22 Friday Homework', status: 'completed' },
    ];
}